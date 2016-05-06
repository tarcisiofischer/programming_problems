import numpy as np

# Configuration
plot_results = False
random = np.random.uniform
n_points = 10000000
n_times = 2


inside_count = 0.0
for i in xrange(n_times):
    ps = random(size=(n_points, 2))
    points_inside_circle = np.sum(ps ** 2, axis=1) - 1.0 < 0
    inside_count += np.sum(points_inside_circle)
total_points = n_points * n_times
print 4.0 * inside_count / total_points

if plot_results:
    import matplotlib.pyplot as plt
    ins = ps[points_inside_circle]
    ous = ps[~points_inside_circle]
    plt.plot(ins[:, 0], ins[:, 1], 'ro')
    plt.plot(ous[:, 0], ous[:, 1], 'bo')
    plt.show()
