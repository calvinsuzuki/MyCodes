import numpy as np
from finiteDiff import finiteDiff

points = [ (0, 0),
        (0, 1),
        (1, 0),
        (1, 1)]

bigFerro = finiteDiff()

bigFerro.createGrid( 5, 5, 10 )

bigFerro.plot()



