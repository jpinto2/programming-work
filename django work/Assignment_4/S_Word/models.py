from django.db import models

# Create your models here.

class submissions(models.Model):
    date=models.DateTimeField()
    topic=models.CharField(max_length=144)

    def __str__(self):
        return str(self.date) + " : " + str(self.topic)

    class Meta:
        ordering = ["date"]
