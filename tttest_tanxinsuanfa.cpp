#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
struct node {
    ll position;
    ll radius;
    ll value;
    ll inx;
};

bool cmp1(node a, node b) {
    return a.position - a.radius < b.position - b.radius;
}

bool cmp2(node a, node b) {
    return a.position + a.radius < b.position + b.radius;
}

node arr_left[10100];
node arr_right[10100];
ll inx_ans[10100];

int main() {
    ios::sync_with_stdio(false);
    ll ans = 0;
    ll temp_max = 0;
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr_left[i].position;
        arr_right[i].position = arr_left[i].position;
        arr_right[i].inx = arr_left[i].inx = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr_left[i].radius;
        arr_right[i].radius = arr_left[i].radius;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr_left[i].value;
        arr_right[i].value = arr_left[i].value;
    }
    sort(arr_left, arr_left + n, cmp1);
    sort(arr_right, arr_right + n, cmp2);
    int inx = 0;
    for (int i = 0; i < n; i++) {
        ll left_ = arr_left[i].position - arr_left[i].radius;
        while (arr_right[inx].position + arr_right[inx].radius <= left_) {
            temp_max = max(temp_max, inx_ans[arr_right[inx].inx]);
            inx++;
        }
        ans = max(ans, temp_max + arr_left[i].value);
        inx_ans[arr_left[i].inx] = temp_max + arr_left[i].value;
    }
    cout << ans << endl;
    return 0;
}