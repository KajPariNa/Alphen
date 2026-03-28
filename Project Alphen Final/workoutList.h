#ifndef WORKOUTLIST_H
#define WORKOUTLIST_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class WorkoutList
{
public:
    vector<T> workouts;

    void clear() { workouts.clear(); }
    bool empty() const { return workouts.empty(); }
    size_t size() const { return workouts.size(); }

    void push_back(const T& item) { workouts.push_back(item); }
    T& operator[](size_t i) { return workouts[i]; }
    const T& operator[](size_t i) const { return workouts[i]; }

    vector<T>& items() { return workouts; }
    const vector<T>& items() const { return workouts; }
};

#endif
