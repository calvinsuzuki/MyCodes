from cv2 import cartToPolar
import numpy as np

# This function solves the problem to fill complex figures
# by calculating it barycenter and generating triangles
def __triangularization(points):

    # Duplicates the inner vertices
    aux = []
    for i in range(len(points)):
        aux.append(points[i])
        aux.append(points[i])
    points = aux.copy()
    points.pop(0)
    points.pop(len(points)-1)

    # Calculates the barycenter of the figure
    medX, medY = 0, 0
    for i in range(len(points)):
        medX += points[i][0]
        medY += points[i][1]
    center = (medX/len(points), medY/len(points))

    # Append to agroup triplets of points (triangles)
    for i in range(len(aux), 0, -1):
        if (i%2 == 0) & (i != 0) & (i != len(aux)):
            points.insert(i, center)

    return points

def Planet():
    # Earth points
    planet = np.zeros((101,2))
    # Making a circle
    for counter in range(101):
        angle = (2 * np.pi / 100) * counter
        x,y = np.cos(angle),  np.sin(angle)
        planet[counter] = [x,y]
    return planet

def Continent():

    # South America corners
    southAmerica = [
        (0.0579357315266, -0.9068283014548),
        (0.0981462836543, -0.8099458674214),
        (0.1516491169932, -0.7323275147239),
        (0.2584815593625, -0.6716173942614),
        (0.3390758879264, -0.6095306648022),
        (0.3810908878453, -0.5552957236495),
        (0.4848372427153, -0.5458642368432),
        (0.5394286430619, -0.4964283030322),
        (0.5665767950371, -0.4106795926186),
        (0.6460680127308, -0.331622004453),
        (0.5697206239726, -0.2629196326522),
        (0.4424837615447, -0.195899170329),
        (0.3936662035871, -0.1088720148149),
        (0.3087828223298, -0.0648584097185),
        (0.2050364674598, 0.0263126294097),
        (0.0643987236278, 0.0820094900203),
        (-0.1004075749514, -0.0375558638509),
        (-0.1502162022466, -0.1245911594922),
        (-0.0874815907491, -0.2702235794921),
        (0, -0.3639369649587),
        (-0.0519351341928, -0.6321511371562),
        (0, -0.8665347882596),
        (0.0579357315266, -0.9068283014548)]

    continent = __triangularization(southAmerica)

    # Central America corners
    centralAmerica = [
        (-0.1451615223118, -0.049582587636),
        (-0.1004075749514, -0.0375558638509),
        (-0.1405370064797, -0.0125864609792),
        (-0.1729086173044, 0.0128483760973),
        (-0.1752208752205, 0.0799038556627),
        (-0.2399640968698, 0.1030264348232),
        (-0.2260905493735, 0.1747064302206),
        (-0.2746479656105, 0.1770186881367),
        (-0.3070195764352, 0.142334819396),
        (-0.3763873139166, 0.144647077312),
        (-0.540557625956, 0.1562083668922),
        (-0.3671382822524, 0.1007141769071),
        (-0.3116440922673, 0.0614057923343),
        (-0.2307150652056, 0.0313464394257),
        (-0.2260905493735, -0.0125864609792),
        (-0.1451615223118, -0.049582587636) ]

    continent += __triangularization(centralAmerica)

    # North America corners
    northAmerica = [
        (-0.3763873139166, 0.144647077312),
        (-0.540557625956, 0.1562083668922),
        (-0.3907647305705, 0.2501818459817),
        (-0.3079536331121, 0.3211627866604),
        (-0.1849200026024, 0.3211627866604),
        (-0.1352333441273, 0.2998685044568),
        (-0.1257692187035, 0.2525478773376),
        (-0.0902787483642, 0.2691100968293),
        (-0.0879127170082, 0.3448231002199),
        (0, 0.4),
        (0.0895396346885, 0.500981169713),
        (0.1534224812993, 0.5246414832725),
        (0.2362335787577, 0.5483017968321),
        (0.3166786448602, 0.5837922671714),
        (0.3143126135042, 0.657139239206),
        (0.4633725889294, 0.6949957409013),
        (0.4, 0.8),
        (0.2835542058768, 0.8558858731063),
        (0.2, 0.8),
        (0.0942716974004, 0.7470484307324),
        (0.0422190075694, 0.7541465248002),
        (-0.0263959017534, 0.7801728697157),
        (0.1250301050278, 0.8842782493778),
        (0.0493171016372, 0.9481610959886),
        (-0.0618863720927, 0.9434290332767),
        (-0.1991161907381, 0.9647233154803),
        (-0.3032215704001, 0.9670893468362),
        (-0.4025948873503, 0.9363309392088),
        (-0.4948701102325, 0.8913763434456),
        (-0.5800472390469, 0.8393236536146),
        (-0.6557602424375, 0.7896369951396),
        (-0.6486621483697, 0.7399503366645),
        (-0.6462961170137, 0.6169167061548),
        (-0.7504014966757, 0.498615138357),
        (-0.7314732458281, 0.4087059468307),
        (-0.6486621483697, 0.3329929434401),
        (-0.5634850195553, 0.1981291561507),
        (-0.3763873139166, 0.144647077312)
        ]

    continent += __triangularization(northAmerica)

    return np.array(continent)

def Sun():
    # Sun points
    sun = np.zeros((101,2))
    # Making a circle
    for counter in range(101):
        angle = (2 * np.pi / 100) * counter
        x,y = np.cos(angle),  np.sin(angle)
        sun[counter] = [x,y]
    return sun

def Moon():
    # Moon points
    moon = np.zeros((101,2))
    # Making a circle
    for counter in range(101):
        angle = (2 * np.pi / 100) * counter
        x,y = np.cos(angle),  np.sin(angle)
        moon[counter] = [x,y]
    return moon

def Ship():
    # Ship points
    ship =  [
    (0.0, +0),
    (+0.05, 0.1),
    (0.05, 0.03),
    (0.1, 0),
    (0.04, 0.06),
    (0.06, 0.06),
    (0.05, 0.07)
    ]
    
    return np.array(ship) 

def Tire():
    tire = np.zeros((101,2))
    # Making a circle
    for counter in range(101):
        angle = (2 * np.pi / 100) * counter
        x,y = np.cos(angle),  np.sin(angle)
        tire[counter] = [x,y]

    return tire

def Car():
    
    car = [
        (-2, .4),
        (2, .4),
        (2, 2.2),
        (-.2, 2.2),
        (-.85, 1.4),
        (-2, 1.4),
        (-2, .4)
        ]
    
    return np.array(car)

    #car = __triangularization(southAmerica)

def Stars():
    # Star points
    stars = 100*(np.random.rand(1000000, 2))-100*(np.random.rand(1000000, 2))
    return np.array(stars)