class Solution {
public:
string prefix = "http://tinyurl.com";
    unordered_map<int, string> p; 
    int key = 0;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        p[key ++] = longUrl;
        return prefix + to_string(key - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string k = shortUrl.substr(prefix.length());
        int m = stoi(k);
        return p[m];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
