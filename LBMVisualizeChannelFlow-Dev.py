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

parameters = np.genfromtxt(r'parameters.txt', unpack=True)

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


x, y, fx, fy, vort_field = np.genfromtxt(r'data_time_dependent.txt', unpack=True)

print('done reading')
print(len(x))
print("--- %s seconds ---" % (time.time() - start_time))


#norm = np.sqrt(fx**2+fy**2)


X = np.array(np.reshape(x, (timesteps, ny, nx)))
Y = np.array(np.reshape(y, (timesteps, ny, nx)))
U = np.array(np.reshape(fx, (timesteps, ny, nx)))
V = np.array(np.reshape(fy, (timesteps, ny, nx)))
VortField = np.array(np.reshape(vort_field, (timesteps, ny, nx)))

print(X.shape)
print(Y.shape)
print(U.shape)
print(V.shape)

#In order for the script to work ffmpeg needs to be downloaded. The .exe can be downloaded at https://www.ffmpeg.org/ 

plt.rcParams['animation.ffmpeg_path']='C:/Users/d-w-h/Desktop/Home/Programs/ffmpeg-20190318-15d016b-win32-static/bin/ffmpeg.exe'
writer=manimation.FFMpegWriter(bitrate=20000, fps=15)


fig = plt.figure(figsize=(8,4))
ax = plt.axes(xlim=(nx_low, nx_high-1), ylim=(ny_low, ny_high-1))  
plt.xlabel(r'x')
plt.ylabel(r'y')

xlow = 0
xhigh = nx
ylow = 0
yhigh = ny 

Vfieldnorm = np.log(1 + (VortField**2)**(0.5))
Velocity = ((U**2 + V**2)**(0.5))
Velocitynorm = 1/(Velocity + 1e-16)

def animate(i):
    print(i)
    plt.gcf().clear()
    ax = plt.axes(xlim=(nx_low + 1/2, nx_high - 1/2), ylim=(ny_low + 1/2, ny_high - 1/2))
    #VField = VortField[i,:,xlow:xhigh]
    VField = Vfieldnorm[i,:,xlow:xhigh]
    z = Velocity[i,:,xlow:xhigh]
    x = (X[i,:,xlow:xhigh])
    y = (Y[i,:,xlow:xhigh])
    u = (U[i,:,xlow:xhigh])
    v = (V[i,:,xlow:xhigh])
    Vnorm = Velocitynorm[i,:,xlow:xhigh]


    xquiv = x[::4,::8]
    yquiv = y[::4,::8]
    uquiv = u[::4,::8]
    vquiv = v[::4,::8]

    #vecnorm = Vnorm[::4,::8]

    #uquiv = vecnorm * u[::4,::8]
    #vquiv = vecnorm * v[::4,::8]

    #Ones = np.array(np.ones(np.shape(xquiv)))
    #uquiv = 100 * np.log(1 + uquiv)
    #vquiv = 100 * np.log(1 + vquiv)

    #cont = plt.contourf(x, y, VField, linspace(0, 0.1, 250), cmap=cm.Reds)
    cont = plt.contourf(x, y, VField, linspace(0, max_vorticity, 250), cmap='RdBu_r')
    #cont = plt.contourf(x, y, VField, norm=colors.SymLogNorm(linthresh=0.03, linscale=0.03, vmin=-1.0, vmax=1.0),cmap='RdBu_r')
    #cont = plt.contourf(x, y, z, linspace(0, max_velocity, 250))
    #P = plt.streamplot(x,y,u,v)         

    for p in [
        patches.Rectangle(
        (0, 0), 0, 0),

        patches.Rectangle(
        (0, 0), 0, 0)
    ]:
        ax.add_patch(p)
    
    cbar = plt.colorbar(cont)

    Q = plt.quiver(xquiv, yquiv, uquiv, vquiv, pivot='mid', angles='xy', width=0.0005, color='w')
    #Q = plt.quiver(xquiv, yquiv, uquiv, vquiv, pivot='mid', angles='xy', color='w')
    
    return cont


print("Starting Animation")

anim = manimation.FuncAnimation(fig, animate, frames=timesteps-1, repeat=False)

print("Done Animation, start saving")

anim.save('Sim_Vid_test_3.mp4',
          writer=writer, dpi=200)
    
print("--- %s seconds ---" % (time.time() - start_time))