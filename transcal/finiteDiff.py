import numpy as np
from element import Element
from matplotlib import pyplot as plt

class finiteDiff :

    def __setLimits( self, X, Y ) :
        xBorder = (max(X)-min(X)) * .1 + 1
        yBorder = (max(Y)-min(Y)) * .1 + 1
        self.xlim = ( min(X)-xBorder, max(X)+xBorder )
        self.ylim = ( min(Y)-yBorder, max(Y)+yBorder )

    def insertPoints( self, points ) :

        self.elements = [ ]

        X, Y = zip(*points)

        self.__setLimits( X, Y )

        for point in points : 
            self.elements.append( Element( x = point[0], y = point[1] ) )
            
    def plot( self ) :
        plt.rcParams["figure.figsize"] = [7.0, 7.0]
        plt.rcParams["figure.autolayout"] = True
        plt.xlim( self.xlim )
        plt.ylim( self.ylim )
        plt.grid()
        for element in self.elements : 
            plt.plot( element.x, element.y, marker="o", markersize=10, markerfacecolor="green" )
            print( "->(" + str(element.x) + ", " + str(element.y) + ")")
        plt.show()

        print( len(self.elements) )

    def createGrid( self, x_len, y_len, lenght ) :
        X = np.linspace( 0, lenght*(x_len-1), x_len ) - lenght*(x_len-1) / 2
        Y = np.linspace( 0, lenght*(y_len-1), y_len ) - lenght*(y_len-1) / 2 

        self.__setLimits( X, Y )

        self.elements = [ ]

        for i in X : 
            for j in Y :
                self.elements.append( Element( x = i, y = j ) )
                print( "(" + str(i) + ", " + str(j) + ")")

    