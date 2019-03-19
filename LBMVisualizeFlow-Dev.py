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


x, y, u, v, vort_field = np.genfromtxt(r'data_time_dependent_0.txt', unpack=True)

print('done reading')
print(len(x))
print("--- %s seconds ---" % (time.time() - start_time))

fig = plt.figure(figsize=(8,4))
ax = plt.axes(xlim=(nx_low, nx_high-1), ylim=(ny_low, ny_high-1))  
plt.xlabel(r'x')
plt.ylabel(r'y')

xlow = 0
xhigh = nx
ylow = 0
yhigh = ny 

Vfieldnorm = np.log(1 + (vort_field**2)**(0.5))
Velocity = ((u**2 + v**2)**(0.5))
Velocitynorm = 1/(Velocity + 1e-16)

def animate(i):
    print(i)
    plt.gcf().clear()
    ax = plt.axes(xlim=(nx_low + 1/2, nx_high - 1/2), ylim=(ny_low + 1/2, ny_high - 1/2))
    VField = vort_field
    z = Velocity
    Vnorm = Velocitynorm


    xquiv = x[::4]
    yquiv = y[::4]
    uquiv = u[::4]
    vquiv = v[::4]

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

#anim = manimation.FuncAnimation(fig, animate, frames=timesteps-1, repeat=False)
anim = manimation.FuncAnimation(fig, animate, fames=1, repeat=False)

print("Done Animation, start saving")

anim.save('Sim_Vid_test_3.mp4',
          writer=writer, dpi=200)
    
print("--- %s seconds ---" % (time.time() - start_time))