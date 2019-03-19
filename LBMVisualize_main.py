import numpy as np
import matplotlib.pyplot as plt
from matplotlib.pyplot import cm
from numpy import *
from pylab import *
from matplotlib.patches import Circle
import matplotlib.animation as manimation
import matplotlib.patches as patches
import matplotlib.colors as colors
import time
import math


start_time = time.time()

print("--- %s seconds ---" % (time.time() - start_time))

parameters = np.genfromtxt(r'./SimData/parameters.txt', unpack=True)

print(parameters)
print(parameters[0])

nx_low = int(parameters[0])
nx_high = int(parameters[1])
ny_low = int(parameters[2])
ny_high = int(parameters[3])
timesteps = int(parameters[4])
max_velocity = parameters[5]
max_vorticity = parameters[6]

nx = nx_high - nx_low
ny = ny_high - ny_low

print(nx)
print(ny)

plt.rcParams['animation.ffmpeg_path']='C:/Users/d-w-h/Desktop/Home/Programs/ffmpeg-20190318-15d016b-win32-static/bin/ffmpeg.exe'
writer=manimation.FFMpegWriter(bitrate=20000, fps=15)

fig = plt.figure(figsize=(8,4))
ax = plt.axes(xlim=(nx_low, nx_high-1), ylim=(ny_low, ny_high-1))  
plt.xlabel(r'x')
plt.ylabel(r'y')

def animate(i):

    x, y, fx, fy, vort_field = np.genfromtxt(r'./SimData/data_time_dependent_' + str(i*100) + '.txt', unpack=True)

    print("--- %s seconds ---" % (time.time() - start_time))

    X = np.array(np.reshape(x, (1, ny, nx)))
    Y = np.array(np.reshape(y, (1, ny, nx)))
    U = np.array(np.reshape(fx, (1, ny, nx)))
    V = np.array(np.reshape(fy, (1, ny, nx)))
    VortField = np.array(np.reshape(vort_field, (1, ny, nx)))

    xlow = 0
    xhigh = nx
    ylow = 0
    yhigh = ny 

    Vfieldnorm = np.log(1 + (VortField**2)**(0.5))
    Velocity = ((U**2 + V**2)**(0.5))
    Velocitynorm = 1/(Velocity + 1e-16)

    print(i)
    plt.gcf().clear()
    ax = plt.axes(xlim=(nx_low + 1/2, nx_high - 1/2), ylim=(ny_low + 1/2, ny_high - 1/2))
    VField = Vfieldnorm[0,:,xlow:xhigh]
    z = Velocity[0,:,xlow:xhigh]
    x = (X[0,:,xlow:xhigh])
    y = (Y[0,:,xlow:xhigh])
    u = (U[0,:,xlow:xhigh])
    v = (V[0,:,xlow:xhigh])
    Vnorm = Velocitynorm[0,:,xlow:xhigh]

    xquiv = x[::4,::8]
    yquiv = y[::4,::8]
    uquiv = u[::4,::8]
    vquiv = v[::4,::8]

    cont = plt.contourf(x, y, VField, linspace(0, max_vorticity, 250), cmap='RdBu_r')        

    for p in [
        patches.Rectangle(
        (0, 0), 0, 0),

        patches.Rectangle(
        (0, 0), 0, 0)
    ]:
        ax.add_patch(p)
    
    cbar = plt.colorbar(cont)

    Q = plt.quiver(xquiv, yquiv, uquiv, vquiv, pivot='mid', angles='xy', width=0.0005, color='w')
    
    return cont


print("Starting Animation")

anim = manimation.FuncAnimation(fig, animate, frames=timesteps-1, repeat=False)

print("Done Animation, start saving")

anim.save('Sim_Results.mp4',
          writer=writer, dpi=200)

print("--- %s seconds ---" % (time.time() - start_time))