template <class Iteaator>
void print(std::ostream &os, Iteaator first, Iteaator last) {
    std::copy(first, last,
              std::ostream_iterator<std::decay_t<decltype(*first)>>(os, " "));
}
template <class Iteaator> void print(Iteaator first, Iteaator last) {
    print(std::cout, first, last);
}
template <class Iteaator>
void println(std::ostream &os, Iteaator first, Iteaator last) {
    print(os, first, last);
    os.put('\n');
}
template <class Iteaator> void println(Iteaator first, Iteaator last) {
    println(std::cout, first, last);
}
