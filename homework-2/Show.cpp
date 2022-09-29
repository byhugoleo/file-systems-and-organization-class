#include "Show.hpp"

using namespace std;

/*---------- Getters/Setters ----------*/

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
    if (title.empty())
        title = "none";
    this->title = title;
}

string Show::getDirector() {
    return this->director;
}

void Show::setDirector(string director) {
    if (director.empty())
        director = "none";
    this->director = director;
}

vector<string> Show::getCast() {
    return this->cast;
}

void Show::setCast(vector<string> cast) {
    if (cast.empty())
        Show::addCast("none");
    this->cast = cast;
}

string Show::getCountry() {
    return this->country;
}

void Show::setCountry(string country) {
    if (country.empty())
        country = "none";
    this->country = country;
}

string Show::getDataAdded() {
    return this->data_added;
}

void Show::setDataAdded(string data_added) {
    if (data_added.empty())
        data_added = "none";
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
    if (rating.empty())
        rating = "none";
    this->rating = rating;
}

string Show::getDuration() {
    return this->duration;
}

void Show::setDuration(string duration) {
    if (duration.empty())
        duration = "none";
    this->duration = duration;
}

vector<string> Show::getListedIn() {
    return this->listed_in;
}

void Show::setListedIn(vector<string> listed_in) {
    if (listed_in.empty())
        Show::addListedIn("none");
    this->listed_in = listed_in;
}

string Show::getDescription() {
    return this->description;
}

void Show::setDescription(string description) {
    if (description.empty())
        description = "none";
    this->description = description;
}
/*---------- Methods ----------*/

void Show::addCast(string actor) {
    this->cast.push_back(actor);
}

void Show::addListedIn(string genere) {
    this->listed_in.push_back(genere);
}

void Show::setProperties(string properties) {
    stringstream ss(properties);
    for (int i = 0; i < 12; i++) {
        if (i == DESCRIPTION) {
            getline(ss, properties, '\n');
            Show::setDescription(properties);
            break;
        }
        getline(ss, properties, ';');
        if (i == SHOW_ID) {
            Show::setShowId(properties);
        } else if (i == TYPE) {
            Show::setType(properties);
        } else if (i == TITLE) {
            Show::setTitle(properties);
        } else if (i == DIRECTOR) {
            Show::setDirector(properties);
        } else if (i == CAST) {
            stringstream actors(properties);
            while (getline(actors, properties, ',')) {
                Show::addCast(properties);
            }
        } else if (i == COUNTRY) {
            Show::setCountry(properties);
        } else if (i == DATA_ADDED) {
            Show::setDataAdded(properties);
        } else if (i == RELEASE_YEAR) {
            Show::setReleaseYear((short)atoi(properties.c_str()));
        } else if (i == RATING) {
            Show::setRating(properties);
        } else if (i == DURATION) {
            Show::setDuration(properties);
        } else if (i == LISTED_IN) {
            stringstream genres(properties);
            while (getline(genres, properties, ',')) {
                Show::addListedIn(properties);
            }
        }
    }
}
/*---------- toString ----------*/

string Show::toString() {
    stringstream ss;
    ss << "show_id: " << this->show_id << "\n"
        << "type: " << this->type << "\n"
        << "title: " << this->title << "\n"
        << "director: " << this->director << "\n"
        << "cast: ";
    for (vector<string>::iterator it = this->cast.begin(); ; it++) {
        if (++it == this->cast.end()) {
            ss << *(--it) << "\n";
            break;
        }
        ss << *it << ", ";
    }
    ss << "country: " << this->country << "\n"
        << "data_added: " << this->data_added << "\n"
        << "release_year: " << this->release_year << "\n"
        << "rating: " << this->rating << "\n"
        << "duration: " << this->duration << "\n"
        << "listed_in: ";
    for (vector<string>::iterator it = this->listed_in.begin(); ; it++) {
        if (++it == this->listed_in.end()) {
            ss << *(--it) << "\n";
            break;
        }
        ss << *it << ", ";
    }
    ss << "description: " << this->description << "\n";
    return ss.str();
}