class Time:
    def time_to_seconds(self):
        return self.seconds + (self.minutes * 60) + (self.hours * 3600)
    def increment(self, time_in_seconds):
        return self.time_to_seconds() + time_in_seconds
    
t1 = Time()
t1.hours = 1
t1.minutes = 1
t1.seconds = 1
print(t1.time_to_seconds())
print(t1.increment(60))

        

       