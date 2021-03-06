#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import print_function

import cv2
import numpy as np

def leeImagen(nombre, flagColor):
    if flagColor == True:
        flag = cv2.IMREAD_COLOR
    else:
        flag = cv2.IMREAD_GRAYSCALE
    return cv2.imread(nombre,flag)

def pintaSecuenciaImagenes(imagenes):
    # El ancho total será la suma de los anchos de todas las imágenes
    # El alto total será el máximo de los altos de todas las imágenes
    ancho_total = sum([img.shape[1] for img in imagenes])
    alto_total = max([img.shape[0] for img in imagenes])

    # Creamos una imagen vacia para ir rellenando
    tira_imagenes = np.zeros((alto_total,ancho_total,3), np.uint8)

    # Rellenamos la tira de imagenes
    ancho_anterior = 0
    for indice_imagen in range(len(imagenes)):
        imagen_actual = imagenes[indice_imagen]
        # Si no están a color, las convertimos
        if len(imagen_actual.shape) < 3:
            imagen_actual = cv2.cvtColor(imagen_actual,cv2.COLOR_GRAY2RGB)

        for indice_fila in range(imagen_actual.shape[0]):
            for indice_columna in range(imagen_actual.shape[1]):
                tira_imagenes[indice_fila][indice_columna + ancho_anterior] = imagen_actual[indice_fila][indice_columna]
        ancho_anterior = ancho_anterior + imagen_actual.shape[1]

    # Visualizamos
    cv2.imshow("Tira imágenes",tira_imagenes)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# Aquí cargamos imágenes con varios flags
imagenes = [leeImagen("lena.jpg",True) for i in range(3)]
imagenes.append(leeImagen("lena.jpg",False))
pintaSecuenciaImagenes(imagenes)
