import sys
import numpy as np
import matplotlib.pyplot as plt
from os import listdir
from os.path import isfile, join
from pathlib import Path

legend = []
outputResultFolderPath = sys.argv[1]
outputResultFiles = [f for f in listdir(outputResultFolderPath) if isfile(join(outputResultFolderPath, f))]
for i in range(0, len(outputResultFiles)):
    fileName = outputResultFiles[i]
    x_data, y_data = [], []
    for row in np.loadtxt(outputResultFolderPath + fileName, delimiter=','):
        x_data.append(float(row[0]))
        y_data.append(float(row[1]))
    plt.plot(x_data, y_data)
    legend.append(Path(fileName).stem)

plt.xlabel('Input Size')
plt.ylabel('Time (In Seconds)')
plt.title(sys.argv[2])
plt.legend(legend)
plt.grid(True)
plt.show()
        