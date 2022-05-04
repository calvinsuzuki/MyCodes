import opengl as gh
import objects as objs
import transform as trans
import time
import numpy as np
import glfw
from OpenGL.GL import *

def scale_move_rot(s=100, x=0, y=0, angle=0 ) : 
    mat_transform = trans.createEyeMat()
    mat_transform = trans.scale(s/100, s/100, mat_transform)
    mat_transform = trans.translate(x/100, y/100, mat_transform)
    mat_transform = trans.rotateZ(angle, mat_transform)
    return mat_transform

def car_object( color=(0,0,0), S=100, X=0, Y=0, Angle=0) :
    ## BODY
    comp_transform = scale_move_rot( s = 20, angle=Angle )
    obj_transform = scale_move_rot( s=S, x=X, y=Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = color[0], color[1], color[2]
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, 0, len(car))
    ## RIGHT WHEEL
    # OUTSIDE
    comp_transform = scale_move_rot( s = 10, x = 22, y = 8, angle=Angle )
    obj_transform = scale_move_rot( s=S, x=X, y=Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .1, .1, .1
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))
    # INSIDE
    comp_transform = scale_move_rot( s = 5, x = 22, y = 8, angle=Angle )
    obj_transform = scale_move_rot( s=S, x=X, y=Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .2, .2, .2
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))
    ## LEFT WHEEL
    # OUTSIDE
    comp_transform = scale_move_rot( s = 10, x = -22, y = 8, angle=Angle )
    obj_transform = scale_move_rot( s=S, x=X, y=Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .1, .1, .1
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))
    # INSIDE
    comp_transform = scale_move_rot( s = 5, x = -22, y = 8, angle=Angle )
    obj_transform = scale_move_rot( s=S, x=X, y=Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .2, .2, .2
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))

def rectangle( color=(0,0,0), s=100, x=0, y=0, angle=0 ):
    mat_transform = scale_move_rot( s, x, y, angle )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = color[0], color[1], color[2]
    glUniform4f( loc_color, R, G, B, 1.0 )
    glDrawArrays(GL_TRIANGLE_FAN, len(car)+len(tire), len(ground))

def car_inverted( color=(0,0,0), S=100, X=0, Y=0, Angle=0) :
    ## BODY
    comp_transform = scale_move_rot( s = 20, angle=Angle )
    obj_transform = scale_move_rot( s=S, x=-X, y=Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )

    # flip in x matrix
    flipX = np.array([[-1.0, 0.0, 0.0, 0],
                        [0.0, 1.0, 0.0, 0],
                        [0.0, 0.0, 1.0, 0.0],
                        [0.0, 0.0, 0.0, 1.0]], np.float32)            
    mat_transform = np.dot(flipX, mat_transform)

    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = color[0], color[1], color[2]
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, 0, len(car))
    ## RIGHT WHEEL
    # OUTSIDE
    comp_transform = scale_move_rot( s = 10, x = 22, y = 8, angle=Angle )
    obj_transform = scale_move_rot( s=S, x=X, y=Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .1, .1, .1
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))
    # INSIDE
    comp_transform = scale_move_rot( s = 5, x = 22, y = 8, angle=Angle )
    obj_transform = scale_move_rot( s=S, x=X, y=Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .2, .2, .2
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))
    ## LEFT WHEEL
    # OUTSIDE
    comp_transform = scale_move_rot( s = 10, x = -22, y = 8, angle=Angle )
    obj_transform = scale_move_rot( s=S, x=X, y=Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .1, .1, .1
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))
    # INSIDE
    comp_transform = scale_move_rot( s = 5, x = -22, y = 8, angle=Angle )
    obj_transform = scale_move_rot( s=S, x=X, y=Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .2, .2, .2
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))

# Create the window with the given parameters
window = gh.createWindow(800, 800, "Move: WASD or ArrowKeys, Rotate: to left Q and to right E")

# Configure shaders and construct variables
program = gh.configGPU()

# Import objects 
tire = objs.Tire()
car = objs.Car()
ground = objs.Ground()

# Sets 'vertices' array size
total_len = len(tire) + len(car) + len(ground)
vertices = np.zeros(total_len, [("position", np.float32, 2)])

# Fill 'vertices' with the objects points
aux0 = 0
aux1 = len(car)
vertices['position'][aux0:aux1] = car
aux0 = aux1
aux1 += len(tire)
vertices['position'][aux0:aux1] = tire
aux0 = aux1
aux1 += len(ground)
vertices['position'][aux0:aux1] = ground

# Sets the GPU Buffer
gh.GPUBuffer(program, vertices)

loc_color = glGetUniformLocation(program, "color")

# set all the initial values of the variables to 0, to avoid problems with division
tx, ty = 0, -.2
theta = 0
color1 = ( 0, 0, 0 )
color2 = ( 1, 1, 0 )

glfw.show_window(window)

t0 = time.time()

while not glfw.window_should_close(window):

    glfw.poll_events()

    glClear(GL_COLOR_BUFFER_BIT)

    # set background color
    glClearColor(0.4, 0.6, 0.4, 1.0) # grass green

    loc = glGetUniformLocation(program, "mat_transformation")

    #  verify the rotation limit before vary the angle
    if abs(theta + gh.dtheta) < .5 :
        theta += gh.dtheta
    #  verify the translation limit before vary the angle
    if abs(tx + gh.dt_x) < 1 :
        tx += gh.dt_x
    if abs(ty + gh.dt_y) < 1 :
        ty += gh.dt_y    

    # resets the variations values
    gh.dt_x = 0
    gh.dt_y = 0
    gh.dtheta = 0

    # ground
    rectangle( color=(.28, .25, .25), s = 200, x = 0, y = -130 )

    # yellow marks
    t = 200*time.time() - t0
    t %= 1000

    rectangle( color=(1,1,0), s = 10, x = -120+t%250, y = -20 )
    rectangle( color=(1,1,0), s = 10, x = -120+(t+80)%250, y = -20 )
    rectangle( color=(1,1,0), s = 10, x = -120+(t+160)%250, y = -20 )

    # cars    
    if t%250 < 2 :
        color1 = (np.random.rand(), np.random.rand(), np.random.rand())
    if (t+120)%250 < 2:
        color2 = (np.random.rand(), np.random.rand(), np.random.rand())

    car_inverted( color1 , S = 100, X = -120+t%250, Y = 20 )
    car_inverted( color2 , S = 100, X = -120+(t+120)%250, Y = -60 )

    # Sets the controlable car
    car_object( color = (.2, 0, 1), S = 100, X = 100*tx, Y = 100*ty, Angle = theta )

    glfw.swap_buffers(window)

glfw.terminate()

