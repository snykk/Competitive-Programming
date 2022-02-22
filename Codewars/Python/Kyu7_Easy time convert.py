def time_convert(num):
    if num >0:
        hours = num//60
        minutes = num - hours*60
        if hours < 10 and minutes <10:
            return '0'+ str(hours) + ':' + '0' + str(minutes)
        elif hours >=10 and minutes <10:
            return str(hours) + ':' + '0' + str(minutes)
        elif hours < 10 and minutes >= 10:
            return '0'+ str(hours) + ':' + str(minutes)
        elif hours >= 10 and minutes >= 10:
            return str(hours) + ':' + str(minutes)
    if num <= 0:
        return '00:00'
