package jpabook.jpaitem.domain;

import jakarta.persistence.Entity;

@Entity
public class Movie extends Item {
    private String director;
    private String actor;
    private String name;
    private String price;
}
