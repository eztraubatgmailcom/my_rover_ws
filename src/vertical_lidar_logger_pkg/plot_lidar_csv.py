import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  # Needed even if unused
import numpy as np

# ========= CONFIG ============
CSV_FILE = "/home/rover/vertical_lidar_log_20250506_152553.csv"  # <-- Update to your latest!
Z_MIN = 0.01   # Filter out startup junk
Z_MAX = 5.0    # Optional: crop long runs
# =============================

# Load CSV
df = pd.read_csv(CSV_FILE)

# Drop rows with invalid or missing values
df = df.replace([np.inf, -np.inf], np.nan).dropna()
df = df[(df['z'] > Z_MIN) & (df['z'] < Z_MAX)]

print(f"Loaded {len(df)} points")

# Create 3D scatter plot
fig = plt.figure(figsize=(10, 6))
ax = fig.add_subplot(111, projection='3d')
p = ax.scatter(df['x'], df['y'], df['z'], c=df['y'], cmap='viridis', s=0.5)

ax.set_xlabel('X (sideways)')
ax.set_ylabel('Y (height)')
ax.set_zlabel('Z (forward)')
ax.set_title('3D Vertical LIDAR Point Curtain')

plt.colorbar(p, label='Height (Y)')
plt.tight_layout()
plt.show()
