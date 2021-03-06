#include "../inc/image.hpp"
#include "../inc/utils.hpp"
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc, char const *argv[]) {


  Image lena(string("imagenes/lena.jpg"),false);
  Image lena_conv = lena.GaussConvolution(3);
  lena.paint();
  lena_conv.paint();

  waitKey(0);
  destroyAllWindows();

  Image einstein(string("imagenes/einstein.bmp"),true);
  Image marilyn(string("imagenes/marilyn.bmp"),true);

  Image low = einstein.GaussConvolution(3);
  Image hybrid = einstein.createHybrid(marilyn,true,6,6);
  Image high = marilyn.highFrecuencies(3);

  vector<Image*> secuencia;
  secuencia.push_back(&low);
  secuencia.push_back(&hybrid);
  secuencia.push_back(&high);

  Image tira(secuencia,1,3);
  tira.paint();

  waitKey(0);
  destroyAllWindows();

  vector<Image*> pyramid;
  Image hybrid_d1 = hybrid.downsample();
  Image hybrid_d2 = hybrid_d1.downsample();
  Image hybrid_d3 = hybrid_d2.downsample();
  Image hybrid_d4 = hybrid_d3.downsample();
  pyramid.push_back(&hybrid);
  pyramid.push_back(&hybrid_d1);
  pyramid.push_back(&hybrid_d2);
  pyramid.push_back(&hybrid_d3);
  pyramid.push_back(&hybrid_d4);

  Image pyramidImage(pyramid, 1,5);

  pyramidImage.paint();

  waitKey(0);
  destroyAllWindows();

  Image derivative_x = einstein.calcFirstDerivative(3,'x');
  Image derivative_y = einstein.calcFirstDerivative(3,'y');
  Image derivative2_x = einstein.calcSecondDerivative(3,'x');
  Image derivative2_y = einstein.calcSecondDerivative(3,'y');
  derivative_x.paint();
  derivative_y.paint();
  derivative2_x.paint();
  derivative2_y.paint();

  waitKey(0),
  destroyAllWindows();

  Image bicycle(string("imagenes/bicycle.bmp"),true);
  Image edges_bicycle = bicycle.detectEdges(40,60);

  bicycle.paint();
  edges_bicycle.paint();

  waitKey(0);
  destroyAllWindows();

  return 0;
}
