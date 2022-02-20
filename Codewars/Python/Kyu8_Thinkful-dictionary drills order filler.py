def fillable(stock, merch, n):
    if merch in stock:
        if stock[merch] >= n:
            return True
        else:
            return False
    else:
        return False