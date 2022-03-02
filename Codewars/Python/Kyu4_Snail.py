def snail(snail_map):
    
    ls = []
    if len(snail_map) == 0:
        return ls
    start_row = 0
    end_row = len(snail_map) - 1
    start_col = 0
    end_col = len(snail_map[0]) - 1

    while start_row <= end_row and start_col <= end_col:

        # up row
        i = start_col
        while i <= end_col:
            ls.append(snail_map[start_row][i])
            i += 1
        start_row += 1

        # rigth col
        i = start_row
        while i <= end_row:
            ls.append(snail_map[i][end_col])
            i += 1
        end_col -= 1

        # bot row
        if start_row <= end_row:
            i = end_col
            while i >= start_col:
                ls.append(snail_map[end_row][i])
                i -= 1
        end_row -= 1

        # left col
        if start_col <= end_col:
            i = end_row
            while i >= start_row:
                ls.append(snail_map[i][start_col])
                i -= 1
        start_col += 1

    return ls