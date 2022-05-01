import numpy as np

def Tire():
    tire = np.zeros((101,2))

    for counter in range(101):
        angle = (2 * np.pi / 100) * counter
        x,y = np.cos(angle),  np.sin(angle)
        tire[counter] = [x,y]

    return tire

def Car():
    
    car = [
        (-2.2, .4),
        (2, .4),
        (2, 1),
        (1.5, 1.8),
        (-.2, 1.8),
        (-.85, 1),
        (-2.2, 1),
        (-2.2, .4)
        ]
    
    return np.array(car)

def Ground(): 
    
    ground = [
        (-2, 0),
        (2, 0),
        (2, .9),
        (-2, .9),
        (-2, 0)
        ]

    return ground
