class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth, sz, heavy, head, pos, val;
    int timer;

    struct SegmentTree {
        int n;
        vector<int> t;

        SegmentTree(int n) {
            this->n = n;
            t.assign(4 * n, 0);
        }

        void build(int node, int l, int r, vector<int>& a) {
            if(l == r) {
                t[node] = a[l];
                return;
            }

            int mid = (l + r) / 2;
            build(node*2, l, mid, a);
            build(node*2+1, mid+1, r, a);
            t[node] = t[node*2] ^ t[node*2+1];
        }

        void update(int node, int l, int r, int idx, int x) {
            if(l == r) {
                t[node] = x;
                return;
            }

            int mid = (l + r) / 2;

            if(idx <= mid)
                update(node*2, l, mid, idx, x);
            else
                update(node*2+1, mid+1, r, idx, x);

            t[node] = t[node*2] ^ t[node*2+1];
        }

        int query(int node, int l, int r, int ql, int qr) {
            if(ql <= l && r <= qr) return t[node];
            if(r < ql || l > qr) return 0;

            int mid = (l + r) / 2;

            return query(node*2, l, mid, ql, qr) ^
                   query(node*2+1, mid+1, r, ql, qr);
        }
    };

    void dfs1(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        heavy[u] = -1;

        for(int v : adj[u]) {
            if(v == p) continue;

            depth[v] = depth[u] + 1;
            dfs1(v, u);

            sz[u] += sz[v];

            if(heavy[u] == -1 || sz[v] > sz[heavy[u]])
                heavy[u] = v;
        }
    }

    void dfs2(int u, int h, vector<int>& base, string& s) {
        head[u] = h;
        pos[u] = timer;
        base[timer++] = (1 << (s[u] - 'a'));

        if(heavy[u] != -1)
            dfs2(heavy[u], h, base, s);

        for(int v : adj[u]) {
            if(v == parent[u] || v == heavy[u]) continue;
            dfs2(v, v, base, s);
        }
    }

    int pathQuery(int u, int v, SegmentTree& st) {
        int mask = 0;

        while(head[u] != head[v]) {
            if(depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= st.query(1, 0, st.n-1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if(depth[u] > depth[v]) swap(u, v);

        mask ^= st.query(1, 0, st.n-1, pos[u], pos[v]);

        return mask;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        adj.assign(n, {});

        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        sz.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);

        timer = 0;
        dfs1(0, -1);

        vector<int> base(n);
        dfs2(0, 0, base, s);

        SegmentTree st(n);
        st.build(1, 0, n-1, base);

        vector<bool> ans;

        for(string str : queries) {
            if(str[0] == 'q') {
                int u, v;
                sscanf(str.c_str(), "query %d %d", &u, &v);

                int mask = pathQuery(u, v, st);
                ans.push_back((mask & (mask - 1)) == 0);
            } else {
                int u;
                char c;
                sscanf(str.c_str(), "update %d %c", &u, &c);

                s[u] = c;
                st.update(1, 0, n-1, pos[u], 1 << (c - 'a'));
            }
        }

        return ans;
    }
};