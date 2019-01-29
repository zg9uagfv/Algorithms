#Graham 扫描法找凸包(convexHull)
#参考:https://www.cnblogs.com/nowgood/p/GrahamconvexHull.html

points = [
    {'x':1, 'y':1},
    {'x':8, 'y':0},
    {'x':16, 'y':8},
    {'x':2, 'y':8},
    {'x':4, 'y':4},
    {'x':0, 'y':5},
    {'x':12, 'y':6},
    {'x':8, 'y':4},
    {'x':6, 'y':2}
]

def isOnLeft(p0, p1, p2):
    '''
    右手定则，向量叉积
    :param p0:
    :param p1:
    :param p2:
    :return:
    '''
    return ((p1['x'] - p0['x']) * (p2['y'] - p0['y'])) >= ((p1['y'] - p0['y']) * (p2['x'] - p0['x']))

def get_min_idx(points, x_min, y_min):
    start_idx = 0x00
    for idx in range(len(points)):
        if points[idx]['y'] < y_min:
            y_min = points[idx]['y']
            x_min = points[idx]['x']
            start_idx = idx
        elif points[idx]['y'] == y_min:
            x_min = points[idx]['x']
            start_idx = idx
    return start_idx, x_min, y_min

def normalize(points, x_min, y_min):
    '''
    以初始点作为原点进行归一化处理
    :param points:
    :param x_min:
    :param y_min:
    :return:
    '''
    for point in points:
        point['y'] -= y_min
        point['x'] -= x_min
    return None

def sort_points(points):
    '''
    逆时针进行排序
    :param points:
    :return:
    '''
    def compare(p0, p1):
        if int(p0['x']*p1['y']) == int(p1['x']*p0['y']):
            return int((p0['x']*p0['x'])+(p0['y']*p0['y'])) < ((p1['x']*p1['x'])+(p1['y']*p1['y']))
        else:
            return int(p0['x']*p1['y'] > p1['x']*p0['y'])

    for out_idx in range(1, len(points)):
        point = points[out_idx]
        idx = len(points[0:out_idx])
        if True == compare(point, points[0]):
            points.pop(out_idx)
            points.insert(0, point)
        else:
            while idx > 0x00:
                if True == compare(point, points[idx-1]):
                    idx -= 1
                    continue
                else:
                    points.pop(out_idx)
                    points.insert(idx, point)
                    break
    return None

def run(points):
    x_min = y_min = 655535
    min_idx, x_min, y_min = get_min_idx(points, x_min, y_min)
    points.pop(min_idx)
    normalize(points, x_min, y_min)
    sort_points(points)

    convexHulls = [{'x':0, 'y':0}]
    convexHulls.append(points[0])
    idx = 0x01
    while idx < len(points):
        p0 = convexHulls[-2]
        p1 = convexHulls[-1]
        p2 = points[idx]
        if True == isOnLeft(p0, p1, p2):
            convexHulls.append(points[idx])
            idx += 1
        else:
            convexHulls.pop()

    print("\nConvexHulls:\b")
    for point in convexHulls:
        point['x'] += x_min
        point['y'] += y_min
        print("(%f, %s)" % (point['x'], point['y']))
    return None

run(points)
