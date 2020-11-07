from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.

def index(request):
    context = {
        "hello": "CINS465 Hello World"
    }
    return render(request, 'index.html', context)
