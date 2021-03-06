// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from weather.idl

package com.wta.weather;

import java.util.ArrayList;

public final class DataBlock {


    /*package*/ final String summary;

    /*package*/ final String icon;

    /*package*/ final ArrayList<DataPoint> data;

    public DataBlock(
            String summary,
            String icon,
            ArrayList<DataPoint> data) {
        this.summary = summary;
        this.icon = icon;
        this.data = data;
    }

    public String getSummary() {
        return summary;
    }

    public String getIcon() {
        return icon;
    }

    public ArrayList<DataPoint> getData() {
        return data;
    }
}
