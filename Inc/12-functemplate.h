#ifndef __12_FUNCTEMPLATE__
#define __12_FUNCTEMPLATE__

class stone {
   public:
    stone() : _w(0), _h(0), _weight(0) {}
    stone(int w, int h) : _w(w), _h(h), _weight(w * h) {}
    bool operator<(const stone& rhs) const {
        return _weight < rhs._weight;
    }

   private:
    int _w, _h, _weight;
};

template <class T>
inline const T& min(const T& a, const T& b) {
    return b < a ? b : a;
}

#endif