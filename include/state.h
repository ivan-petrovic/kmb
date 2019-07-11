#include "engine/core/kmb.h"
#include "engine/core/random_kmb_generator.h"
#include "engine/core/kmb_set_abstract.h"
#include "engine/core/kmb_set7.h"
#include "engine/core/kmb_set6.h"
#include "engine/core/kmb_set5.h"
#include "engine/core/kmb_set4.h"
#include "engine/core/kmb_set3.h"
#include "engine/core/kmb_set2.h"
#include "engine/core/kmb_set1.h"
#include "engine/stat/stat_win.h"

#ifndef __STATE_H__
#define __STATE_H__

struct State
{
    random_kmb_generator gen;

    kmb curr_kmb;
    int curr_index;

    kmb win_kmb;
    int win_index;
    
    kmb_set7 all7;
    kmb_set6 all6;
    kmb_set5 all5;
    kmb_set4 all4;
    kmb_set3 all3;
    kmb_set2 all2;
    kmb_set1 all1;

    stat_win sw;

    int result;
    std::vector<int> positions;
    kmb_set_abstract generated_kmbs;
    kmb_set_abstract save1;
    // kmb_set_abstract save2;

    bool keep_running;
};

#endif // __STATE_H__
