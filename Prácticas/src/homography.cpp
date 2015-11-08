#include "../inc/homography.hpp"

Mat Homography::homographyEquationMatrix(vector<Point> origin, vector<Point> destination)
{
  if (origin.size() != destination.size())
  {
    return Mat::zeros(3,3,CV_32FC1);
  }

  int num_points = origin.size();
  int num_equations = 2 * num_points;

  Mat coeffs = Mat::zeros(num_equations, 9, CV_32FC1);

  Point ori, dest;

  for (int i = 0; i < num_points; i++)
  {
    ori = origin[i];
    dest = destination[i];

    int actual_row = 2 * i;
    int next_row = actual_row + 1;

    coeffs.at<float>(Point(0,actual_row)) = ori.x;
    coeffs.at<float>(Point(1,actual_row)) = ori.y;
    coeffs.at<float>(Point(2,actual_row)) = 1;
    coeffs.at<float>(Point(6,actual_row)) = -dest.x * ori.x;
    coeffs.at<float>(Point(7,actual_row)) = -dest.x * ori.y;
    coeffs.at<float>(Point(8,actual_row)) = -dest.x;

    coeffs.at<float>(Point(3,next_row)) = ori.x;
    coeffs.at<float>(Point(4,next_row)) = ori.y;
    coeffs.at<float>(Point(5,next_row)) = 1;
    coeffs.at<float>(Point(6,next_row)) = -dest.y * ori.x;
    coeffs.at<float>(Point(7,next_row)) = -dest.y * ori.y;
    coeffs.at<float>(Point(8,next_row)) = -dest.y;
  }

  return coeffs;
}

Mat Homography::calcHomography(vector<Point> origin, vector<Point> destination)
{
  Mat A = homographyEquationMatrix(origin,destination);

  Mat u, vt, w;
	SVD::compute(A, w, u, vt);

  Mat homography_matrix = Mat(3, 3, CV_32FC1);
	for (int i = 0; i < 9; i++)
  {
		homography_matrix.at<float>(Point(i % 3, floor(i / 3))) = vt.at<float>(Point(i,vt.cols -1 ));
	}

  return homography_matrix;
}

Homography::Homography(vector<Point> origin, vector<Point> destination)
{
  this->homography = this->calcHomography(origin,destination);
}

Mat Homography::getHomography()
{
  return homography;
}
