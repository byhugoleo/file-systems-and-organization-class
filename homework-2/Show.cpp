#include "Show.hpp"

using namespace std;

string Show::getShowId() {
    return this->show_id;
}

void Show::setShowId(string show_id) {
    this->show_id = show_id;
}

string Show::getType() {
    return this->type;
}

void Show::setType(string type) {
    this->type = type;
}

string Show::getTitle() {
    return this->title;
}

void Show::setTitle(string title) {
    this->title = title;
}

string Show::getDirector() {
    return this->director;
}

void Show::setDirector(string director) {
    this->director = director;
}

vector<string> Show::getCast() {
    return this->cast;
}

void Show::setCast(vector<string> cast) {
    this->cast = cast;
}

string Show::getCountry() {
    return this->country;
}

void Show::setCountry(string country) {
    this->country = country;
}

string Show::getDataAdded() {
    return this->data_added;
}

void Show::setDataAdded(string data_added) {
    this->data_added = data_added;
}

short Show::getReleaseYear() {
    return this->release_year;
}

void Show::setReleaseYear(short release_year) {
    this->release_year = release_year;
}

string Show::getRating() {
    return this->rating;
}

void Show::setRating(string rating) {
    this->rating = rating;
}

string Show::getDuration() {
    return this->duration;
}

void Show::setDuration(string duration) {
    this->duration = duration;
}

vector<string> Show::getListedIn() {
    return this->listed_in;
}

void Show::setListedIn(vector<string> listed_in) {
    this->listed_in = listed_in;
}

string Show::getDescription() {
    return this->description;
}

void Show::setDescription(string description) {
    this->description = description;
}

void Show::addCast(string actor) {
    this->cast.push_back(actor);
}

void Show::addListedIn(string genere) {
    this->listed_in.push_back(genere);
}
