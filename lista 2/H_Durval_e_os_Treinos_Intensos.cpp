#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

struct track {
    int first;
    int second;
};

bool compare_entry(track &e1, track &e2) {
    int dif1, dif2;
    dif1 = e1.second - e1.first;
    dif2 = e2.second - e2.first;

    if (e1.first != e2.first)
        return (e1.first < e2.first);
    return (dif1 < dif2);
}

void can_select(vector<track> &paths, track new_track) {
    if (paths.size() == 0) {
        paths.push_back(new_track);
        return;
    }

    track last_track = paths.back();

    if (last_track.second > new_track.second) {
        paths.pop_back();
        paths.push_back(new_track);
    } else if (last_track.second < new_track.first) {
        paths.push_back(new_track);
    }
}

int main() {
    int n, i;
    track new_track;
    vector<track> tracks, paths;

    cin >> n;
    for (i = 0; i < n; i++) {
        new_track = track();
        cin >> new_track.first >> new_track.second;
        tracks.push_back(new_track);
    }

    sort(tracks.begin(), tracks.end(), compare_entry);

    for (i = 0; i < tracks.size(); i++) {
        can_select(paths, tracks[i]);
    }

    cout << paths.size() << endl;

    return 0;
}