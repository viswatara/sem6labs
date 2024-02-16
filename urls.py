from django.urls import path as url
from . import views
urlpatterns = [
	url('', views.index, name='index'),
]