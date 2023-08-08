auto f(std::vector<int> const& c){
    auto sum = 0;
    for (int i = 0; i != static_cast<int>(c.size()); ++i){
        auto const& v = c[i];
        sum += v;
    }
}
