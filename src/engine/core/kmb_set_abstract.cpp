#include <iostream>
#include <fstream>
#include "engine/core/kmb_set_abstract.h"
#include "engine/constants.h"


const int kmb_set_abstract::EXCLUDED = 60;
const int kmb_set_abstract::VISITED = 59;

kmb_set_abstract::kmb_set_abstract()
: num(0), MAX(0), initialized(false) {
}

void kmb_set_abstract::init() {
    if(initialized) {
        std::cout << "Already initialized with " << num << "s.\n";
        return;
    }

    _init();
}

void kmb_set_abstract::_init() {
    initialized = true;
    MAX = 0;
    num = 0;
}

void kmb_set_abstract::add(kmb k) {
    kmbs.push_back(k);
}

void kmb_set_abstract::clear() {
    kmbs.clear();
}

int kmb_set_abstract::find_index(kmb k) {
    if (k.count() != num) {
        std::cout << "Error in find index in " << num << "s.\n";
        return -1;    
    }
    for (int i = 0; i < MAX; i += 1) {
        if (k.intersection(kmbs[i]).count() == num) {
            return i;
        }
    }
    return -1;
}

void kmb_set_abstract::mark_positions(kmb k, int flag) {
    for (int i = 0; i < MAX; i += 1) {
        if(k.intersection(kmbs[i]).count() == num) {
            kmbs[i].set(flag);
        }
    }
}

void kmb_set_abstract::mark_positions(std::vector<int> positions, int flag) {
    for (int i = 0; i < positions.size(); i += 1) {
        int position = positions[i];
        kmbs[position].set(flag);
    }
}

std::vector<int> kmb_set_abstract::find_positions(kmb k) {
    std::vector<int> result;

    for (int i = 0; i < MAX; i += 1) {
        if(k.intersection(kmbs[i]).count() == num) {
            result.push_back(i);
        }
    }
    
    return result;
}

std::vector<int> kmb_set_abstract::find_unvisited_positions(kmb k) {
    std::vector<int> result;

    for (int i = 0; i < MAX; i += 1) {
        if(k.intersection(kmbs[i]).count() == num) {
            if(!check(i, VISITED)) result.push_back(i);
            // if(!kmbs[i].check(VISITED)) result.push_back(i);
        }
    }
    
    return result;
}

int kmb_set_abstract::filter_out(kmb k, unsigned int n) {
    unsigned int cnt = 0;
    
    for (int i = 0; i < kmbs.size(); i += 1) {
        if (kmbs[i].check(EXCLUDED)) {
            continue;
        }
        if (k.intersection(kmbs[i]).count() >= n) {
            kmbs[i].set(EXCLUDED);
        } else {
            cnt += 1;
        }
    }
    
    return cnt;
}

int kmb_set_abstract::filter_out(int index, kmb_set_abstract & kmb_set, unsigned int n) {
    unsigned int cnt = 0;
    if (kmb_set.check(index, VISITED)) { // kmb_set[index].check(VISITED)
        return cnt;
    }
    kmb_set.kmbs[index].set(VISITED);
    
    for (int i = 0; i < MAX; i += 1) {
        if (kmbs[i].check(EXCLUDED)) {
            continue;
        }
        if (kmb_set.kmbs[index].intersection(kmbs[i]).count() >= n) {
            kmbs[i].set(EXCLUDED);
        } else {
            cnt += 1;
        }
    }
    
    return cnt;
}

bool kmb_set_abstract::check(int index, int flag) {
    return kmbs[index].check(flag);
}

void kmb_set_abstract::clear(int flag) {
    for (int i = 0; i < kmbs.size(); i += 1) {
        kmbs[i].unset(flag);
    }
}

void kmb_set_abstract::save(std::string file_name) const {
    std::ofstream out_file(file_name.c_str());
    
    if(!out_file.is_open()) {
        std::cout << "Error opening file " << file_name << ".\n";
        return;
    }

    for (int i = 0; i < kmbs.size(); i += 1) {
        out_file << kmbs[i] << '\n';
    }
}

void kmb_set_abstract::save_raw(std::string file_name) const {
    std::ofstream out_file(file_name.c_str());

    if(!out_file.is_open()) {
        std::cout << "Error opening file " << file_name << ".\n";
        return;
    }

    for (int i = 0; i < kmbs.size(); i += 1) {
        out_file << kmbs[i].raw() << '\n';
    }
}

void kmb_set_abstract::load(std::string file_name) {
    std::ifstream in_file(file_name.c_str());

    if(!in_file.is_open()) {
        std::cout << "Error opening file " << file_name << ".\n";
        return;
    }

    int i1, i2, i3, i4, i5, i6, i7;
    kmb temp;

    while(in_file >> i1 >> i2 >> i3 >> i4 >> i5 >> i6 >> i7) {
        temp.clear();
        temp.set(i1); temp.set(i2); temp.set(i3); temp.set(i4);
        temp.set(i5); temp.set(i6); temp.set(i7);
        kmbs.push_back(temp);
    }
}

void kmb_set_abstract::load_raw(std::string file_name) {
    std::ifstream in_file(file_name.c_str());

    if(!in_file.is_open()) {
        std::cout << "Error opening file " << file_name << ".\n";
        return;
    }

    unsigned long long temp;
    while(in_file >> temp) {
        kmb k(temp);
        kmbs.push_back(k);
    }
}

void kmb_set_abstract::print(kmb w) const {
    std::cout << "winning: " << w << std::endl;

    unsigned int cnt = 0;

    for (int i = 0; i < kmbs.size(); i += 1) {
        if (kmbs[i].check(EXCLUDED)) {
            continue;
        }
        std::cout << kmbs[i] << " (" << w.intersection(kmbs[i]).count() << ")\n";
        cnt += 1;
    }
    std::cout << "total: " << cnt << std::endl;
}
