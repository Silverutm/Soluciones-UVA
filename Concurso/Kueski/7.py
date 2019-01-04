import sys
import os
import urllib2
import json

import requests
def  getNumberOfMovies(substr):
    la_url = "https://jsonmock.hackerrank.com/api/movies/search/"
    solicitud = requests.get(la_url, params={'Title' : substr})
    return solicitud.json()['total']

getNumberOfMovies("maze")