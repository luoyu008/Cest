#define _CRT_SECURE_NO_WARNINGS
//公交站间的距离
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination) {
    int sumdis = 0;
    for (int i = 0; i < distanceSize; i++) {
        sumdis += distance[i];
    }
    int curdis = 0;
    for (int i = (start < destination ? start : destination); i < (destination > start ? destination : start); i++) {
        curdis += distance[i];
    }
    return sumdis - curdis < curdis ? sumdis - curdis : curdis;
}