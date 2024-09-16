#define _CRT_SECURE_NO_WARNINGS
//����վ��ľ���
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