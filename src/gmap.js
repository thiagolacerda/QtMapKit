var map = null;
var markers = {};

function initialize(lng, lat, type, zoom) {
    var mapOptions = {
        'center': new google.maps.LatLng(lat, lng),
        'mapTypeId': type,
        'zoom': zoom
    };
    map = new google.maps.Map(document.getElementById('map_canvas'),
                              mapOptions);
    google.maps.event.addListener(map, 'bounds_changed', function() {
        var bounds = map.getBounds();
        var ne = bounds.getNorthEast();
        var sw = bounds.getSouthWest();
        qMapView.regionDidChangeTo(ne.lat(), sw.lat(), ne.lng(), sw.lng());
    });
    google.maps.event.addListener(map, 'center_changed', function() {
        var center = map.getCenter();
        qMapView.centerDidChangeTo(center.lat(), center.lng());
    });
    google.maps.event.addListener(map, 'click', function(e) {
        var p = e.latLng;
        qMapView.mouseDidClickAt(p.lat(), p.lng());
    });
    google.maps.event.addListener(map, 'dblclick', function(e) {
        var p = e.latLng;
        qMapView.mouseDidDoubleClickAt(p.lat(), p.lng());
    });
    google.maps.event.addListener(map, 'rightclick', function(e) {
        var p = e.latLng;
        qMapView.mouseDidRightClickAt(p.lat(), p.lng());
    });
    google.maps.event.addListener(map, 'drag', function() {
        qMapView.mouseDragged();
    });
    google.maps.event.addListener(map, 'dragstart', function() {
        qMapView.mouseDragStarted();
    });
    google.maps.event.addListener(map, 'dragend', function() {
        qMapView.mouseDragEnded();
    });
    google.maps.event.addListener(map, 'heading_changed', function() {
        qMapView.headingChanged();
    });
    google.maps.event.addListener(map, 'idle', function() {
        qMapView.mapBecameIdle();
    });
    google.maps.event.addListener(map, 'maptypeid_changed', function() {
        qMapView.mapTypeDidChangeTo(map.getMapTypeId());
    });
    google.maps.event.addListener(map, 'mousemove', function(e) {
        var p = e.latLng;
        qMapView.cursorDidMoveTo(p.lat(), p.lng());
    });
    google.maps.event.addListener(map, 'mouseover', function(e) {
        var p = e.latLng;
        qMapView.cursorDidEnterTo(p.lat(), p.lng());
    });
    google.maps.event.addListener(map, 'mouseout', function(e) {
        var p = e.latLng;
        qMapView.cursorDidLeaveFrom(p.lat(), p.lng());
    });
    google.maps.event.addListener(map, 'tilesloaded', function() {
        qMapView.tilesLoaded();
    });
    google.maps.event.addListener(map, 'tilt_changed', function() {
        qMapView.tilesChanged();
    });
    google.maps.event.addListener(map, 'zoom_changed', function() {
        qMapView.zoomLevelChanged(map.getZoom());
    });
}

function getMarkerIcon(marker) {
    var markerPath;
    switch(marker.type) {
    case 1:
        markerPath = google.maps.SymbolPath.BACKWARD_CLOSED_ARROW;
        break;
    case 2:
        markerPath = google.maps.SymbolPath.BACKWARD_OPEN_ARROW;
        break;
    case 3:
        markerPath = google.maps.SymbolPath.CIRCLE;
        break;
    case 4:
        markerPath = google.maps.SymbolPath.FORWARD_CLOSED_ARROW;
        break;
    case 5:
        markerPath = google.maps.SymbolPath.FORWARD_OPEN_ARROW;
        break;
    default:
        return null;
    }

    return {
        fillColor: marker.color,
        scale: 5,
        path: markerPath
    }
}

function addMarker(key) {
    var nativeMarker = qMapView.getMarker(key);
    var marker = new google.maps.Marker({
        position: new google.maps.LatLng(nativeMarker.latitude, nativeMarker.longitude),
        map: map,
        title: nativeMarker.name,
        animation: google.maps.Animation.DROP,
        icon: getMarkerIcon(nativeMarker)
    });

    google.maps.event.addListener(marker, 'click', function() {
        for (var key in markers) {
            if (markers[key] === marker) {
                qMapView.onMarkerClicked(key);
                return;
            }
        }
    });

    markers[nativeMarker.id] = marker;
}

function getMapBounds() {
    var bounds = map.getBounds();
    var ne = bounds.getNorthEast();
    var sw = bounds.getSouthWest();
    return {
        'north': ne.lng(),
        'south': sw.lng(),
        'east': ne.lat(),
        'west': sw.lat()
    };
}

function getMapCenter() {
    var center = map.getCenter();
    return {
        'latitude': center.lat(),
        'longitude': center.lng()
    }
}

function setMapCenter(lat, lng, animated) {
    var latlng = new google.maps.LatLng(lat, lng);
    if (animated)
        map.panTo(latlng);
    else
        map.setCenter(latlng);
}

function boundsFromCoordinates(north, south, east, west) {
    var ne = new google.maps.LatLng(north, east);
    var sw = new google.maps.LatLng(south, west);
    return new google.maps.LatLngBounds(sw, ne);
}

function panMapToBounds(north, south, east, west) {
    map.panToBounds(boundsFromCoordinates(north, south, east, west));
}

function fitMapToBounds(north, south, east, west) {
    map.fitBounds(boundsFromCoordinates(north, south, east, west));
}
