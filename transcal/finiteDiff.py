import numpy as np
from element import Element
from matplotlib import pyplot as plt

class finiteDiff :

    def __init__( self, fluidTemp, fluidConvection ) :
        self.fluidTemp = fluidTemp
        self.fluidConvection = fluidConvection

    def __setLimits( self, X, Y ) :
        
        self.minX, self.maxX = min(X), max(X)
        self.minY, self.maxY = min(Y), max(Y)

        xBorder = self.maxX-self.minX
        yBorder = self.maxY-self.minY

        border = max(xBorder, yBorder) * .6

        self.markerSize = 5 + int( 10 * np.exp( -border ) )
        
        self.xlim = ( -border, border )
        self.ylim = ( -border, border )

    def insertPoints( self, points ) :

        X, Y = zip(*points)

        self.__setLimits( X, Y )

        self.elements = [ ]

        for point in points : 
            self.elements.append( Element( x = point[0], y = point[1] ) )
            
    def plot( self ) :
        plt.rcParams["figure.figsize"] = [7.0, 7.0]
        plt.rcParams["figure.autolayout"] = True
        plt.xlim( self.xlim )
        plt.ylim( self.ylim )
        plt.grid()

        for element in self.elements : 
            # Place the horizontal and vertical lines
            if element.x == self.minX : 
                plt.plot( [self.minX, self.maxX], [element.y, element.y], 'k--', alpha=.4)
            if element.y == self.minX : 
                plt.plot( [element.x, element.x], [self.minY, self.maxY], 'k--', alpha=.4)
            # Plot the elements
            plt.plot( element.x, element.y, marker="o", markersize=self.markerSize, 
            markerfacecolor=element.color,  markeredgecolor='none' )
                
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
