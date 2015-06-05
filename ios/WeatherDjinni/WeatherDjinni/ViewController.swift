//
//  ViewController.swift
//  WeatherDjinni
//
//  Created by Robert Thompson on 6/4/15.
//  Copyright (c) 2015 WillowTree Apps. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class ViewController: UIViewController, UISearchBarDelegate, MKMapViewDelegate {
    @IBOutlet weak var searchBar: UISearchBar!
    @IBOutlet weak var mapView: MKMapView!
    
    var weatherController: MTWeatherController!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        weatherController = MTWeatherController.createWithNetworkController(NetworkControllerImpl())
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func searchBarSearchButtonClicked(searchBar: UISearchBar) {
        let geocoder = CLGeocoder()
        
        geocoder.geocodeAddressString(searchBar.text, completionHandler: { [weak self]
            (placemarks: [AnyObject]!, error: NSError?) -> Void in
            if let placemark = placemarks.first as? CLPlacemark
            {
                let span = MKCoordinateSpan(latitudeDelta: 0.1, longitudeDelta: 0.1)
                let region = self?.mapView.regionThatFits(MKCoordinateRegion(center: placemark.location.coordinate, span: span))
                self?.mapView.setRegion(region!, animated: true)
                
                self?.mapView.addAnnotation(MKPlacemark(placemark: placemark))
            }
            else if let error = error
            {
                
            }
            
            searchBar.resignFirstResponder()
        })
    }
    
    func mapView(mapView: MKMapView!, didSelectAnnotationView view: MKAnnotationView!) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)) {
            if let placemark = view.annotation as? MKPlacemark
            {
                let result = self.weatherController.forecast(placemark.location.coordinate.latitude, longitude: placemark.location.coordinate.longitude)
                
                dispatch_async(dispatch_get_main_queue()) {
                    let controller = UIAlertController(title: "Current Temperature", message: "\(result.currently.temperature!)ºF", preferredStyle: UIAlertControllerStyle.Alert)
                    controller.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.Cancel, handler: nil))
                    
                    self.presentViewController(controller, animated: true, completion: nil)
                    
                    self.mapView.deselectAnnotation(view.annotation, animated: false)
                }
            }
        }
    }
}

@objc class NetworkControllerImpl : NSObject, MTNetworkController
{
    func get(URI: String) -> NSData {
        return NSData(contentsOfURL: (NSURL(string: URI) ?? NSURL()))!
    }
    
    func post(URI: String, body: NSData) -> NSData {
        return NSData()
    }
}