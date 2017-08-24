//
//  DuplicateErr.h
//  Topic F
//
//  Created by user on 11/17/15.
//  Copyright (c) 2015 CSM20. All rights reserved.
//

#ifndef __Topic_F__DuplicateErr__
#define __Topic_F__DuplicateErr__

#include <stdio.h>
#include <stdexcept>
#include <string>

using namespace std;

class DuplicateErr : public logic_error
{
public:
    DuplicateErr(const string& message = "") : logic_error("Duplicate Item" + message) {}
};

#endif /* defined(__Topic_F__DuplicateErr__) */
