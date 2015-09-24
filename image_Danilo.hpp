/*  Departamento de Informatica, PUC-Rio, INF1761 Computer Graphhics
*    
*   @file image.h TAD: digital image (interface).
*   @original_author Marcelo Gattass and others
*   @changed by Danilo Pereira
*
*   @date
*         Last version:     08/2015.
*
*   @version 3.1
* 
*   @Copyright/License
*   DI PUC-Rio Educational Software
*   All the products under this license are free software: they can be used for both academic and commercial purposes at absolutely no cost. 
*   There are no paperwork, no royalties, no GNU-like "copyleft" restrictions, either. Just download and use it. 
*   They are licensed under the terms of the MIT license reproduced below, and so are compatible with GPL and also qualifies as Open Source software. 
*   They are not in the public domain, PUC-Rio keeps their copyright. The legal details are below. 
* 
*   The spirit of this license is that you are free to use the libraries for any purpose at no cost without having to ask us. 
*   The only requirement is that if you do use them, then you should give us credit by including the copyright notice below somewhere in your product or its documentation. 
*   
*   Copyright � 2010-2015 DI PUC-Rio Educational Software
*
*   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software 
*   without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sub license, and/or sell copies of the Software, and to permit 
*   persons to whom the Software is furnished to do so, subject to the following conditions: 
*   
*   The above copyright notice and this permission notice shall be included in all copies or suavlantial portions of the Software. 
*
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
*   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
*   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
*
*/

#ifndef IMAGE_H
#define IMAGE_H

#include "TwoDimMatrix.hpp"



namespace image
{

/************************************************************************/
/* Tipos Exportados                                                     */
/************************************************************************/
    typedef union
    {
        float vet[3];
        struct {
            float red;
            float green;
            float blue;
        } rgb;
        float luminance;
    } Pixel;


    enum DimensionalSpace { RED, GREEN, BLUE };
/**
 *   Imagem com um buffer rgb.
 */
    class Image
    {
    private:
        float* GetFloatBuffer(); // Get reference

    public:
        Image(unsigned int w, unsigned int h, unsigned int dcs);

        ~Image();

        unsigned int dcs;
        /* define a dim do espaco de cor (dimension of the color space): 3=RGB, 1=luminancia */
        unsigned int width;
        /* numero de pixels na direcao horizontal da imagem */
        unsigned int height;
        /* numero de pixels na direcao vertical da imagem   */
        TwoDimMatrix<Pixel> * buf;      /* vetor de dimensao dcs*width*height que armazena consecutivamente as componentes de cor */
        /* de cada pixel a partir do canto inferior esquerdo da imagem.  */
        /* A posicao das componentes de cor do pixel (x,y) fica armazenada */
        /* a partir da posicao: (y*width*dcs) + (x*dcs)  */


        int GetWidth();

        int GetHeight();

        int GetDimColorSpace();


        /**
         *	Cria uma nova nova copia imagem dada.
         *
         *	@return Handle da imagem criada.
         */
        Image* Copy();

        /**
         *	Cria uma nova nova copia imagem dada em tons de cinza.
         *
         *	@return Handle da imagem criada.
         */
        Image* GreyCopy();

        Image* ResizedCopy(int w1, int h1);

        /**
         *	Le a imagem a partir do arquivo especificado.
         *
         *	@return imagem criada.
         */
        static Image* ReadBMP(const char* filename);

        /**
         *	Salva a imagem no arquivo especificado em formato BMP.
         *
         *	@param filename Nome do arquivo de imagem.
         *
         *	@return retorna 1 caso nao haja erros.
         */
        int WriteBMP(char* filename);


        /**
         *	Salva a imagem no arquivo especificado .
         *
         *	@param filename Nome do arquivo de imagem.
         *	@param image Handle para uma imagem.
         *
         *	@return retorna 1 caso nao haja erros.
         */
        int WritePFM(char* filename);


        /**
         *	Le a imagem a partir do arquivo especificado.
         *  A imagem e' armazenada como um arquivo binario
         *  onde os tres campos da .
         *
         *	@param filename Nome do arquivo de imagem.
         *
         *	@return imagem criada.
         */
        static Image* ReadPFM(char* filename);


        /************************************************************************/
        /* Funcoes Exportadas                                                   */

        /**
             *	 Aplica o filtro de Gauss para eliminar o ruido branco
             *  da imagem.
             *
             *	@param image Handle para uma imagem a ser filtrada.
             *
         */
       static  Image* Gauss(Image* img_src);

        /**
         *	Conta o numero de cores diferentes na imagem
         *
         *	@param w Nova largura da imagem.
         *	@param h Nova altura da imagem.
         */
        int CountColor(float tol);

        /**
         *	 Aplica o filtro de Mediana para eliminar o ruido sal e pimenta
         *  da imagem.
         *
         */
        void Median();

        /**
         *	Ajusta o pixel de uma imagem com a cor especificada.
         *
         *	@param x Posicao x na imagem.
         *	@param y Posicao y na imagem.
         *	@param color Cor do pixel(valor em float [0,1]).
         */
        void SetPixel3fv(int x, int y, float* color);

        void SetPixel3f(int x, int y, float R, float G, float B);

        /**
         *	Ajusta o pixel de uma imagem com a cor especificada.
         *
         *	@param x Posicao x na imagem.
         *	@param y Posicao y na imagem.
         *	@param color Cor do pixel (valor em unsigend char[0,255]).
         */
        void SetPixel3ubv(int x, int y, unsigned char* color);


        /**
         *	Obtem o pixel de uma imagem na posicao especificada.
         *
         *	@param x Posicao x na imagem.
         *	@param y Posicao y na imagem.
         *	@param color [out] Pixel da posicao especificada(valor em float [0,1]).
         */
        void GetPixel3fv(int x, int y, float* color);

        void GetPixel3f(int x, int y, float* R, float* G, float* B);


        /**
         *	Obtem o pixel de uma imagem na posicao especificada.
         *
         *	@param x Posicao x na imagem.
         *	@param y Posicao y na imagem.
         *	@param color [out] Pixel da posicao especificada (valor em unsigend char[0,255]).
         */

        void GetPixel3ubv(int x, int y, unsigned char* color);

        /**
        *	Reduz a imagem em tons de cinza para 2 tons (B&W ou Preto e Branco).
        *
        *   @return Handle para a image de luminosidade com dois tons 0 e 1 (B&W).
        **/
        Image* Binary();

        /**
         *	 Calcula uma imagem com pixels nas arestas
         *  da imagem dada.
         *
         *  @return Handle para a image de luminosidade onde o branco destaca as arestas.
         */
        Image* Edges();
        Image* Erosion();
        Image* Dilatation();

        unsigned int Count();
    };


}


#endif


