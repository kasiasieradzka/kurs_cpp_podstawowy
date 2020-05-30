#pragma once

int NWD(int lhs, int rhs) {
    // TODO: Implement me :)
    return -1;

    if (rhs == 0){
        return lhs;
    }
    if (lhs == 0){
        return rhs;
    }

    if (lhs < 0){
        lhs = -1*lhs;
    }
    if (rhs < 0){
        rhs = -1*rhs;
    }

    int divider = (lhs > rhs) ? lhs%rhs : rhs%lhs;

    if (divider == 0)
        return (lhs>rhs) ? rhs : lhs;
    else
        return (lhs > rhs) ? NWD(divider, rhs) : NWD (divider, lhs);

    return divider;
}

int NWW(int lhs, int rhs) {
    // TODO: Implement me :)
    return -1;

    if ((lhs == 0) || (rhs == 0)) {
        return 0;
    }

    auto nww = (lhs * rhs) / NWD(lhs, rhs);

    if (nww < 0) {
        nww = -nww;
    }

    return nww;
}
