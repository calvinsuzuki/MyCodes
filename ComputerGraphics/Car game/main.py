import opengl as gh
import objects as objs
import transform as trans
import time
import numpy as np
import glfw
from OpenGL.GL import *

def scale_move_rot(s = 100, x = 0, y = 0, angle = 0) : 
    mat_transform = trans.createEyeMat()
    mat_transform = trans.scale(s/100, s/100, mat_transform)
    mat_transform = trans.translate(x/100, y/100, mat_transform)
    mat_transform = trans.rotateZ(angle, mat_transform)
    return mat_transform

def car_object( color = (0,0,0), S = 100, X = 0, Y = 0) :
    ## BODY
    comp_transform = scale_move_rot( s = 20 )
    obj_transform = scale_move_rot( s = S, x = 100*X, y = 100*Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    # matrix = np.array([[-1.0, 0.0, 0.0, 0],
    #                             [0.0, 1.0, 0.0, 0],
    #                             [0.0, 0.0, 1.0, 0.0],
    #                             [0.0, 0.0, 0.0, 1.0]], np.float32)
    # mat_transform = np.dot(matrix, mat_transform)
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = color[0], color[1], color[2]
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, 0, len(car))
    ## RIGHT WHEEL
    # OUTSIDE
    comp_transform = scale_move_rot( s = 10, x = 22, y = 8, angle = theta )
    obj_transform = scale_move_rot( s = S, x = 100*X, y = 100*Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .1, .1, .1
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))
    # INSIDE
    comp_transform = scale_move_rot( s = 5, x = 22, y = 8, angle = theta )
    obj_transform = scale_move_rot( s = S, x = 100*X, y = 100*Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .2, .2, .2
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))
    ## LEFT WHEEL
    # OUTSIDE
    comp_transform = scale_move_rot( s = 10, x = -22, y = 8, angle = theta )
    obj_transform = scale_move_rot( s = S, x = 100*X, y = 100*Y )    # Translate with keyboard
    mat_transform = np.dot( obj_transform, comp_transform )
    glUniformMatrix4fv(loc, 1, GL_TRUE, mat_transform)
    R, G, B = .1, .1, .1
    glUniform4f(loc_color, R, G, B, 1.0)
    glDrawArrays(GL_TRIANGLE_FAN, len(car), len(tire))
    # INSIDE
    comp_transform = scale_move_rot( s = 5, x = -22, y = 8, angle = theta )
    obj_transform = scale_move_rot( s = S, x = 100*X, y = 100*Y )    # Translate with keyboard
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

# Sets 'vertices' array size
total_len = len(tire) + len(car)
vertices = np.zeros(total_len, [("position", np.float32, 2)])

# Fill 'vertices' with the objects points
aux0 = 0
aux1 = len(car)
vertices['position'][aux0:aux1] = car
aux0 = aux1
aux1 += len(tire)
vertices['position'][aux0:aux1] = tire

# Sets the GPU Buffer
gh.setGPUBuffer(program, vertices)

global loc_color
loc_color = glGetUniformLocation(program, "color")

# set all the initial values of the variables to 0, to avoid problems with division
tx = 0
ty = 0
theta = 0
last_tx = 0
last_ty = 0
tx_planet = 0
ty_planet = 0

glfw.show_window(window)

t0 = time.time()

while not glfw.window_should_close(window):

    glfw.poll_events()

    glClear(GL_COLOR_BUFFER_BIT)

    # set background color
    glClearColor(0.4, 0.6, 0.4, 1.0)

    loc = glGetUniformLocation(program, "mat_transformation")

    # this verification don't let the tire get out of the whindow
    if 1 > abs(tx + gh.dt_x*np.cos(theta) - gh.dt_y*np.sin(theta)):
        tx = tx + gh.dt_x*np.cos(theta) - gh.dt_y*np.sin(theta)
    if 1 > abs(ty + gh.dt_x*np.sin(theta) + gh.dt_y*np.cos(theta)):
        ty = ty + gh.dt_x*np.sin(theta) + gh.dt_y*np.cos(theta)

    gh.dt_x = 0
    gh.dt_y = 0
    gh.dtheta = 0

    # Sets the controlable car
    car_object( color = (.2, 0, 1), S = 100, X = tx, Y = ty )
    car_object( S=150, X=tx, Y=ty-.8 )

    glfw.swap_buffers(window)

glfw.terminate()

