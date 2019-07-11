#include <vector>
#include <string>
#include "kmb.h"

#ifndef __KMB_SET_H__
#define __KMB_SET_H__

class kmb_set_abstract
{
protected:
    std::vector<kmb> kmbs;
    unsigned int MAX;
    unsigned int num;
    bool initialized;

public:
    static const int EXCLUDED;
    static const int VISITED;

    kmb_set_abstract();
    virtual ~kmb_set_abstract() = default;
    void init();
    void add(kmb k);
    void clear();

    const std::vector<kmb> & get() const { return kmbs; }
    unsigned int get_size() const  { return kmbs.size(); }

    int find_index(kmb k);

    void mark_positions(kmb k, int flag = VISITED);
    void mark_positions(std::vector<int> positions, int flag = VISITED);
    std::vector<int> find_positions(kmb k);
    std::vector<int> find_unvisited_positions(kmb k);

    int filter_out(kmb k, unsigned int n);
    int filter_out(int index, kmb_set_abstract & kmbs, unsigned int n);

    bool check(int index, int flag);
    void clear(int flag);

    void save(std::string file_name) const;
    void save_raw(std::string file_name) const;
    void load(std::string file_name);
    void load_raw(std::string file_name);

    void print(kmb w) const;

protected:
    virtual void _init();
};

#endif // __KMB_SET_H__ 
