import time
import datetime

today = datetime.date.today()
secs = time.mktime((today.year, today.month, today.day, 0, 0, 0, 0, 0, 0))

print(int(secs * 60))
