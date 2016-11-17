#pragma once

struct FILE_ACCESS_FLAGS {

    FILE_ACCESS_FLAGS()
        : Flags(0)
    {

    }

    enum FLAGS {
        Create =    1 << 0,
        Exists =    1 << 1,
        Truncate =  1 << 2
    };

    void SetFlags( int flags ) {
        Flags = flags;
    }

    bool GetFlag( FLAGS flag ) {
        return Flags & flag != 0;
    }

private:
    int Flags;
};
