 el puzzle sera representado por una lista de enteros donde el largo de esta
es de 9 elementos siempre:

puzzle = [1,2,3,4,5,6,7,8,X]  =   1  2  3
                                  4  5  6
                                  7  8  X
Para obtener un elemento de este puzzle es necesario una coordenada (X,Y)
ya que :

    Elemento = Y*N + X  //donde N es el tamaño de la matriz, para este caso
    N es 3 (debido a que la matriz es de 3x3)

    Finalmente para obtener un elemento en (X,Y) sera:

    Elemento = Y*3+X

    la restricción para X es I= [0,2] o X <= 2 y X >= 0
    la restricción para Y es I= [0,2] o Y <= 2 y Y >= 0
