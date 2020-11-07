from django.shortcuts import render
from django.http import HttpResponse, JsonResponse

# Create your views here.

def index(request):
    context = {
        "grow": "Scroll over me to make me grow"
    }
    return render(request, 'index.html', context)
