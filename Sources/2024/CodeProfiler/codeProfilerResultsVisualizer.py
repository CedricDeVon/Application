import sys
import numpy as np
import matplotlib.pyplot as plt
from os import listdir
from pathlib import Path
from os.path import isfile, join

plt.style.use('seaborn-v0_8-bright')
legend_labels, file_paths, folder_name = [], sys.argv[1], sys.argv[2]
file_names = [file_path for file_path in listdir(file_paths) if isfile(join(file_paths, file_path))]
for current_index in range(0, len(file_names)):
    x_data, y_data, file_name = [], [], file_names[current_index]
    for data_row in np.loadtxt(file_paths + file_name, delimiter=','):
        x_data.append(float(data_row[0]))
        y_data.append(float(data_row[1]))
    plt.plot(x_data, y_data, 'o-')
    legend_labels.append(Path(file_name).stem)

plt.xlabel('Input Size')
plt.ylabel('Time (In Seconds)')
plt.title(f"'{folder_name}' Code running time results")
plt.legend(legend_labels)
plt.grid(True)
plt.show()
        