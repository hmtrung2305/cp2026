class Solution {
public:
    std::vector<int> subarrayMajority(std::vector<int>& a, std::vector<std::vector<int>>& qry) {
        int n = a.size();

        auto sa = a;
        std::sort(sa.begin(), sa.end());
        sa.erase(std::unique(sa.begin(), sa.end()), sa.end());

        int m = sa.size();
        std::vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = std::lower_bound(sa.begin(), sa.end(), a[i]) - sa.begin();
        }

        std::vector<std::vector<int>> pos(m);
        for (int i = 0; i < n; i++) {
            pos[b[i]].push_back(i);
        }

        const int B = std::max(1, (int)sqrt(n));
        int nb = (n + B - 1) / B;

        auto getFreq = [&](int id, int l, int r) {
            if (id < 0) {
                return 0;
            }
            auto it1 = std::lower_bound(pos[id].begin(), pos[id].end(), l);
            auto it2 = std::lower_bound(pos[id].begin(), pos[id].end(), r);
            return (int)(it2 - it1);
        };

        auto work = [&](int id, int freq, int &resid, int &resfreq) {
            if (id < 0) {
                return;
            }
            if (freq > resfreq || (freq == resfreq && (resid == -1 || id < resid))) {
                resfreq = freq;
                resid = id;
            }
        };

        std::vector<std::vector<int>> block(nb, std::vector<int>(nb, -1));
        std::vector<int> cnt(m);
        std::vector<int> zero;
        for (int i = 0; i < nb; i++) {
            int resid = -1;
            int resfreq = 0;
            zero.clear();

            for (int j = i; j < nb; j++) {
                int L = j * B;
                int R = std::min(n, (j + 1) * B);
                for (int k = L; k < R; k++) {
                    int id = b[k];
                    if (cnt[id] == 0) {
                        zero.push_back(id);
                    }
                    cnt[id]++;
                    int freq = cnt[id];
                    work(id, freq, resid, resfreq);
                }
                block[i][j] = resid;
            }
            for (int id : zero) {
                cnt[id] = 0;
            }
        }

        std::vector<bool> vis(m);
        int k = 0;

        std::vector<int> ans;

        for (auto q : qry) {
            int l = q[0];
            int r = q[1];
            int t = q[2];
            int bl = l / B;
            int br = r / B;

            int resid = -1;
            int resfreq = 0;

            if (bl + 1 <= br - 1) {
                int id = block[bl + 1][br - 1];
                work(id, getFreq(id, l, r), resid, resfreq);
            }
            // std::cout << resid << " " << resfreq << " " << bl << " " << br << "\n"; //(resid != -1 ? sa[resid] : -1) << "\n";

            k++;
            for (int i = l; i <= std::min(r, (bl + 1) * B - 1); i++) {
                int id = b[i];
                if (vis[id] == k) {
                    continue;
                }
                vis[id] = k;
                work(id, getFreq(id, l, r), resid, resfreq);
            }
            std::cout << resid << " " << resfreq << "\n";
            for (int i = std::max(l, br * B); i <= r; i++) {
                int id = b[i];
                if (vis[id] == k) {
                    continue;
                }
                vis[id] = k;
                work(id, getFreq(id, l, r), resid, resfreq);
            }

            if (resfreq >= t) {
                ans.push_back(sa[resid]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};