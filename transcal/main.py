import numpy as np
from finiteDiff import finiteDiff

# points = [ (0, 0),
#         (0, 1),
#         (1, 0),
#         (1, 1)]

bigFerro = finiteDiff( 20, 3000)

bigFerro.createGrid( 5, 5, .025 )

bigFerro.plot()



