(GET_NEXT_LINE){
    (st_backup){__get backup[3] -> }
    | strchring..[
        | strlening..[| returning 0]
        | returning 0]
    (st_buffer){__size = 1__buffer = q}
    __backup ||__buffer |q|| strjoining..[
        | strlening..[| returning 0]
        | strlening..[__s[0] = q| returning 1]
        | returning q]
    | strchring..[
        | strlening..[__s[0] = q| returning 1]
        | returning 0]
    (st_buffer){__size = 1__buffer = w}
    __backup |q|__buffer |w|| strjoining..[
        | strlening..[__s[0] = q| returning 1]
        | strlening..[__s[0] = w| returning 1]
        | returning qw]
    | strchring..[
        | strlening..[__s[0] = q__s[1] = w| returning 2]
        | returning 0]
    (st_buffer){__size = 1__buffer = e}
    __backup |qw|__buffer |e|| strjoining..[
        | strlening..[__s[0] = q__s[1] = w| returning 2]
        | strlening..[__s[0] = e| returning 1]
        | returning qwe]
    | strchring..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e| returning 3]
        | returning 0]
    (st_buffer){__size = 1__buffer = r}
    __backup |qwe|__buffer |r|| strjoining..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e| returning 3]
        | strlening..[__s[0] = r| returning 1]
        | returning qwer]
    | strchring..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e__s[3] = r| returning 4]
        | returning 0]
    (st_buffer){__size = 1__buffer = t}
    __backup |qwer|__buffer |t|| strjoining..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e__s[3] = r| returning 4]
        | strlening..[__s[0] = t| returning 1]
        | returning qwert]
    | strchring..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e__s[3] = r__s[4] = t| returning 5]
        | returning 0]
    (st_buffer){__size = 1__buffer = y}
    __backup |qwert|__buffer |y|| strjoining..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e__s[3] = r__s[4] = t| returning 5]
        | strlening..[__s[0] = y| returning 1]
        | returning qwerty]
    | strchring..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e__s[3] = r__s[4] = t__s[5] = y| returning 6]
        | returning 0]
    (st_buffer){__size = 1__buffer = u}
    __backup |qwerty|__buffer |u|| strjoining..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e__s[3] = r__s[4] = t__s[5] = y| returning 6]
        | strlening..[__s[0] = u| returning 1]
        | returning qwertyu]
    | strchring..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e__s[3] = r__s[4] = t__s[5] = y__s[6] = u| returning 7]
        | returning 0]
    (st_buffer){__size = 1__buffer = i}
    __backup |qwertyu|__buffer |i|| strjoining..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e__s[3] = r__s[4] = t__s[5] = y__s[6] = u| returning 7]
        | strlening..[__s[0] = i| returning 1]
        | returning qwertyui]
    | strchring..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e__s[3] = r__s[4] = t__s[5] = y__s[6] = u__s[7] = i| returning 8]
        | returning 0]
    (st_buffer){__size = 1__buffer = o}
    __backup |qwertyui|__buffer |o|| strjoining..[
        | strlening..[__s[0] = q__s[1] = w__s[2] = e__s[3] = r__s[4] = t__s[5] = y__s[6] = u__s[7] = i| returning 8]
        | strlening..[__s[0] = o| returning 1]
        | strchring..[
            | strlening..[