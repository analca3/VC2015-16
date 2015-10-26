#include "../inc/image.hpp"
#include "../inc/utils.hpp"
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc, char const *argv[]) {
  Image prueba(string("Imágenes/lena.jpg"),false);
  // Image prueba2(string("Imágenes/einstein.bmp"),true);
  // prueba.paint();
  // prueba2.paint();
  //
  // waitKey(0);
  // destroyAllWindows();
  //
  //
  // vector<Image*> secuencia;
  // secuencia.push_back(&prueba);
  // secuencia.push_back(&prueba2);
  // secuencia.push_back(&prueba);
  //
  //
  // Image canvas(secuencia,1,3);
  // canvas.paint();
  //
  // waitKey(0);
  // destroyAllWindows();
  //
  // Image prueba3(string("Imágenes/lena.jpg"),true);
  // vector<Point> pixels;
  // for (int i = 0; i < 256; i+=4)
  // {
  //   for (int j = 0; j < 256; j++)
  //     pixels.push_back(Point(j,i));
  // }
  //
  // vector<Vec3b> values;
  // values.push_back(0);
  // prueba3.setPixels(pixels,values);
  // prueba3.paint();
  //
  //
  // waitKey(0);
  // destroyAllWindows();

  cout << "Convolucion" << endl;
  Image prueba2 = prueba.GaussConvolution(3);
  prueba.paint();
  prueba2.paint();
  cout << "convolucion end" << endl;



  waitKey(0);
  destroyAllWindows();

  Image einstein(string("Imágenes/einstein.bmp"),true);
  Image marilyn(string("Imágenes/marilyn.bmp"),true);

  Image hybrid = einstein.createHybrid(marilyn,true,5,2);

  vector<Image*> secuencia;
  secuencia.push_back(&einstein);
  secuencia.push_back(&hybrid);
  secuencia.push_back(&marilyn);

  Image tira(secuencia,1,3);
  tira.paint();

  waitKey(0);
  destroyAllWindows();

  return 0;
}
