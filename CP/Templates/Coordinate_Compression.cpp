// vector < int > a(m), com_val;
// for(int i=0; i<m; i++){
//     cin >> a[i];
//     com_val.pb(a[i]);
//     com_val.pb(a[i]+1);
// }
// sort(all(com_val));
// com_val.resize(unique(all(com_val))-com_val.begin());
// vi cnt(2*m);
// for(auto u: updates){
//     int com_l = lower_bound(all(com_val), u.first)-com_val.begin();
//     int com_r = lower_bound(all(com_val), u.second+1)-com_val.begin();
//     cnt[com_l]++;
//     cnt[com_r]--;
// }
// partial_sum(all(cnt), cnt.begin());
// for(int i=0; i<m; i++){
//     int idx = lower_bound(all(com_val), a[i])-com_val.begin();
//     cout << cnt[idx] << endl;
// }