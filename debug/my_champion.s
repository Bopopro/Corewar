.name "Descriminant"
.comment "Desc o l z l"

start: st r1, :l1
    st r1, :l2
    st r1, :main
    st r1, :mywall
    st r1, :lm
    st r1, :re
    fork %400

l1: live %1

main: live %1
    fork %400
    and r11, r11, r11
    zjmp %:mywall
re: live %1
    fork %400

l2: live %1
    lfork %1
    zjmp %:main

mywall: live %1
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
lm: live %1
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    st r10, -800
    and r11, r11, r11
    zjmp %:re


